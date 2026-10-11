// Offline targeted decompilation; does not edit the program or execute firmware.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.Reference;
import java.nio.file.*;
import java.util.*;
import java.util.regex.Pattern;

public class DumpColorFunctions extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Pattern pattern = Pattern.compile(args[1]);
        int depth = Integer.parseInt(args[2]);
        LinkedHashSet<Function> targets = new LinkedHashSet<>();
        ArrayDeque<Object[]> queue = new ArrayDeque<>();
        if (args[1].startsWith("@")) {
            for (String address : args[1].substring(1).split(",")) {
                for (Reference ref : getReferencesTo(toAddr(Long.parseUnsignedLong(address,16)))) {
                    Function f = getFunctionContaining(ref.getFromAddress());
                    if (f != null) queue.add(new Object[]{f, 0});
                }
            }
        } else {
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (pattern.matcher(f.getName()).find() && !f.isExternal()) {
                    queue.add(new Object[]{f, 0});
                }
            }
        }
        while (!queue.isEmpty() && targets.size() < 100) {
            Object[] item = queue.remove();
            Function f = (Function)item[0];
            int level = (Integer)item[1];
            if (f.isExternal() || f.isThunk() || !targets.add(f)) continue;
            if (level < depth) for (Function c : f.getCalledFunctions(monitor)) {
                queue.add(new Object[]{c, level + 1});
            }
        }
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        StringBuilder output = new StringBuilder();
        for (Function f : targets) {
            output.append("/* FUNCTION ").append(f.getName()).append(" @ ")
                .append(f.getEntryPoint()).append(" body=").append(f.getBody()).append("\n");
            for (Reference ref : getReferencesTo(f.getEntryPoint())) {
                Function caller = getFunctionContaining(ref.getFromAddress());
                output.append("REF ").append(ref.getFromAddress()).append(" ")
                    .append(ref.getReferenceType()).append(" caller=")
                    .append(caller == null ? "NONE" : caller.getName() + "@" + caller.getEntryPoint())
                    .append("\n");
            }
            output.append("*/\n");
            DecompileResults result = decompiler.decompileFunction(f, 60, monitor);
            output.append(result.decompileCompleted() ? result.getDecompiledFunction().getC() : "// FAILED: " + result.getErrorMessage());
            output.append("\n\n");
        }
        decompiler.dispose();
        Files.writeString(Paths.get(args[0]), output.toString());
        println("Wrote " + targets.size() + " functions to " + args[0]);
    }
}
