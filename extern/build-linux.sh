#?/usr/bin/env bash

UNREAL_ENGINE_DIR=/opt/unreal-engine
UNREAL_ENGINE_COMPILER_DIR=$UNREAL_ENGINE_DIR/Engine/Extras/ThirdPartyNotUE/SDKs/HostLinux/Linux_x64/v17_clang-10.0.1-centos7/x86_64-unknown-linux-gnu
UNREAL_ENGINE_LIBCXX_DIR=$UNREAL_ENGINE_DIR/Engine/Source/ThirdParty/Linux/LibCxx
CPLUS_INCLUDE_PATH=/opt/unreal-engine/Engine/Source/ThirdParty/Linux/LibCxx/include/c++/v1
cmake -B build -S . \
  -DCMAKE_SYSTEM_NAME=Linux \
  -DCMAKE_SYSTEM_PROCESSOR=x86_64 \
  -DCMAKE_SYSROOT="${UNREAL_ENGINE_COMPILER_DIR}" \
  -DCMAKE_C_COMPILER="${UNREAL_ENGINE_COMPILER_DIR}"/bin/clang \
  -DCMAKE_CXX_COMPILER="${UNREAL_ENGINE_COMPILER_DIR}"/bin/clang++ \
  -DCMAKE_CXX_FLAGS="-nostdinc++ -I${UNREAL_ENGINE_LIBCXX_DIR}/include -I${UNREAL_ENGINE_LIBCXX_DIR}/include/c++/v1 -I${UNREAL_ENGINE_LIBCXX_DIR}/include/c++/v1" \
  -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
  -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER \
  -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY \
  -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY \
  -DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=ONLY

cmake --build build --target install -j12
${UNREAL_ENGINE_DIR}/Engine/Build/BatchFiles/RunUAT.sh BuildPlugin -Plugin="${PWD}/../CesiumForUnreal.uplugin" -Package="${PWD}/../../packages/CesiumForUnreal" -CreateSubFolder -TargetPlatforms=Linux
