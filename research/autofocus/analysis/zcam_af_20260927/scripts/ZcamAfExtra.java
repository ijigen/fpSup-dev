import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.nio.file.*;
public class ZcamAfExtra extends GhidraScript {
 public void run() throws Exception {
  String[] a=getScriptArgs();
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);
  StringBuilder s=new StringBuilder();
  for(int i=1;i<a.length;i++) {
   var p=toAddr(Long.decode(a[i]));
   Function f=getFunctionAt(p);
   if(f==null) { disassemble(p);f=createFunction(p,"audit_"+a[i]); }
   if(f==null){s.append("NO FUNCTION "+a[i]+"\n");continue;}
   var r=d.decompileFunction(f,120,monitor);
   s.append("/* "+f.getName()+" @ "+p+" */\n");
   s.append(r.decompileCompleted()?r.getDecompiledFunction().getC():r.getErrorMessage());s.append("\n");
  }
  Files.writeString(Paths.get(a[0]),s.toString());d.dispose();
 }
}
