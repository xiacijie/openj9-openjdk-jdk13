rm -rf comp.log* vlog.out*
./build/macosx-x86_64-server-release/images/jdk/bin/javac Test.java
./build/macosx-x86_64-server-release/images/jdk/bin/java '-Xjit:disableAsyncCompilation,disableGuardedCountingRecompilation,enableOWL,limit={*.doTest*},{*.doTest*}(count=1,traceFull,log=comp.log),verbose={comp*},vlog=vlog.out' -Xshareclasses:none Test

cd ./OWL
bash run.sh