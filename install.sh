#!/bin/bash

# Set up for fakeroot
[ ! -x "$(command -v newuidmap)" ] && {
    echo "[Info] 'newuidmap' not found. Start installation."
    sudo apt-get install -y uidmap
}
sudo apptainer config fakeroot --add $USER

cd $(dirname $0)/apptainer

# Build build_environment
if [ ! -f build_environment.sif ]; then
    echo -e '\e[1;36mBuilding build_environment ...\e[m'
    apptainer build --fakeroot build_environment.sif build_environment.def
    if [ $? -ne 0 ]; then
        echo -e $'\e[1;31mFailed to build build_environment.\e[m'
        exit 1
    fi
else
    echo -e '\e[1;36mbuild_environment has already been built.\e[m'
fi

# Build executable
echo -e '\e[1;36mBuilding executable ...\e[m'
apptainer build --force --fakeroot executable.sif executable.def
if [ $? -ne 0 ]; then
    echo -e $'\e[1;31mFailed to build executable.\e[m'
    exit 1
fi

# Install SMTPlan+
echo -e '\e[1;36mInstalling SMTPlan+ ...\e[m'
sudo cp executable.sif /usr/local/bin/SMTPlan
if [ $? -ne 0 ]; then
    echo -e $'\e[1;31mFailed to install.\e[m'
    exit 1
fi
echo -e '\e[1;36mInstalled SMTPlan+ successfully.\e[m'
