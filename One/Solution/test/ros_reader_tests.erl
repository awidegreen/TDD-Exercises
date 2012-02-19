-module(ros_reader_tests).
-include_lib("eunit/include/eunit.hrl").

ros_reads_file_test() ->
    File = "./test/january-good-2011.ros",
    ?assertMatch({ok,Result},ros_reader:read_file(File)).
    
