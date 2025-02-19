#!/usr/bin/env bash
###########################################################################
#    docker-qgis-clangtidy.sh
#    ---------------------
#    Date                 : September 2022
#    Copyright            : (C) 2022 by Julien Cabieces
#    Email                : julien dot cabieces at oslandia dot com
###########################################################################
#                                                                         #
#   This program is free software; you can redistribute it and/or modify  #
#   it under the terms of the GNU General Public License as published by  #
#   the Free Software Foundation; either version 2 of the License, or     #
#   (at your option) any later version.                                   #
#                                                                         #
###########################################################################

set -e

SRCDIR=${CTEST_SOURCE_DIR-/root/QGIS}
cd ${SRCDIR}

# This is needed for `git status` to work, see
# https://github.com/qgis/QGIS/runs/6733585841?check_suite_focus=true#step:13:89
git config --global --add safe.directory ${SRCDIR}

# The clang-tidy version installed needs to match the one used to compile QGIS.
# Otherwise, it will not be able to inspect the modified files.
echo "::group::Install clang tidy"
apt install -y \
    clang-tidy-15
echo "::endgroup::"

cd ${SRCDIR}

echo "${bold}Disable unity build...${endbold}"
cmake . -B build -DENABLE_UNITY_BUILDS=OFF

echo "${bold}Run clang-tidy on modifications...${endbold}"

# We need to add build/src/test dir as extra include directories because when clang-tidy tries to process qgstest.h
# it has no compile_commands.json instructions to know what are include directories
# It manages to figure out for other headers though, I don't get how...
git diff -U0 HEAD^ | python3 /usr/bin/clang-tidy-diff-15.py -p1 -path=${CTEST_BUILD_DIR} -use-color -extra-arg=-I${CTEST_BUILD_DIR}/src/test/ -clang-tidy-binary /usr/bin/clang-tidy-15 | tee clang-tidy.log

echo -e "\e[1;34mTo reproduce locally:"
echo -e "\e[1;34m - launch cmake with option -DCMAKE_EXPORT_COMPILE_COMMANDS=ON"
echo -e "\e[1;34m - update build by calling Ninja"
echo -e "\e[1;34m - launch command ./scripts/clang-tidy.sh -p <your_build_dir> <source_file>"

exit $(grep -c "warning:" clang-tidy.log)
