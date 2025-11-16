SRC_FILES=$(find -name "*.cpp")
INCLUDE_DIRS="-Iinclude"

# set font red
. ~/bashconf.sh
sfc 1

# Compile all
g++ -std=c++17 -O0 $SRC_FILES $INCLUDE_DIRS \
-lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/main

iscompiled=$?

# If compiled, run
if [ $iscompiled -eq 0 ]; then
    bin/main
fi


