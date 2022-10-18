#!/bin/bash

cd $(dirname $0)/singularity

if [ ! -f build_environment.sif ]; then
    echo -e '\e[1;36mBuilding build_environment ...\e[m'
    singularity build --fakeroot build_environment.sif build_environment.def
    if [ $? -ne 0 ]; then
        echo -e $'\e[1;31mFailed to build build_environment.\e[m'
        exit 1
    fi
else
    echo -e '\e[1;36mbuild_environment has already built.\e[m'
fi

if [ ! -f executable_base.sif ]; then
    echo -e '\e[1;36mBuilding executable_base ...\e[m'
    singularity build --fakeroot executable_base.sif executable_base.def
    if [ $? -ne 0 ]; then
        echo -e $'\e[1;31mFailed to build executable_base.\e[m'
        exit 1
    fi
else
    echo -e '\e[1;36mexecutable_base has already built.\e[m'
fi

echo -e '\e[1;36mBuilding executable ...\e[m'
singularity build --fakeroot executable.sif executable.def
if [ $? -ne 0 ]; then
    echo -e $'\e[1;31mFailed to build executable.\e[m'
    exit 1
fi

echo -e '\e[1;36mInstalling SMTPlan+ ...\e[m'
sudo cp executable.sif /usr/local/bin/SMTPlan
if [ $? -ne 0 ]; then
    echo -e $'\e[1;31mFailed to install.\e[m'
    exit 1
fi
echo -e '\e[1;36mInstalled SMTPlan+ successfully.\e[m'
