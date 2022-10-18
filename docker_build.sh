#!/bin/bash

cd $(dirname $0)

if [ ! "$(docker image ls -q "smtplan:build_environment")" ]; then
    echo -e '\e[1;36mBuilding build_environment ...\e[m'
    docker build --file=docker/Dockerfile.build_environment -t smtplan:build_environment .
    if [ $? -ne 0 ]; then
        echo -e $'\e[1;31mFailed to build build_environment.\e[m'
        exit 1
    fi
else
    echo -e '\e[1;36mbuild_environment has already built.\e[m'
fi

echo -e '\e[1;36mBuilding executable ...\e[m'
docker build --rm --file=docker/Dockerfile -t smtplan .
docker image prune -f --filter label=note=smtplan
if [ $? -ne 0 ]; then
    echo -e $'\e[1;31mFailed to build executable.\e[m'
    exit 1
fi

echo -e '\e[1;36mBuild a SMTPlan+ Docker image successfully.\e[m'
