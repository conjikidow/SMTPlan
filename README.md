# SMTPlan+

SMTPlan+ is a planner supporting PDDL+ developed by researchers at King's College London.
This is a fork of the [SMTPlan+](https://github.com/KCL-Planning/SMTPlan) repository.
All copyright for the original source code belongs to the original authors.

The original SMTPlan+ cannot be compiled on Ubuntu 20.04 or later, so this repository provides easy ways to build it on any environment.

## Changes from the Original

The following changes have been made from the original SMTPlan+:

- Added Apptainer (formerly known as Singularity) definition files and installer to easily execute SMTPlan+ on Linux.
- Added Dockerfiles to build an image to execute SMTPlan+ on any environment.
- Removed unused files and libraries.
- Removed EncoderFluent as it is not functioning properly.
- Modified the format for printing solved plans.

## How to run

### Apptainer

To build the Apptainer image and install SMTPlan+ on your host system, just run [install.sh](install.sh).
After installation, you can use `SMTPlan` command on your host environment.

Note that [Apptainer](https://apptainer.org/) (version 1.3.4) is required and currently only available on Linux systems.

### Docker

To build the Docker image, run [docker_build.sh](docker_build.sh).
After build, you can use `SMTPlan` command on a container over the smtplan:latest image.

The Docker image built is also available on [Docker Hub](https://hub.docker.com/r/conjikidow/smtplan).

### Usage

```
SMTPlan domain_file problem_file [options]
```

Run `SMTPlan -h` for more information on a command.


---

Below is the original README.

> # SMTPlan+
> PDDL+ planning through compilation to SMT
>
> Full description on the project website:
> http://kcl-planning.github.io/SMTPlan
>
> The easiest way to get SMTPlan is now through planutils:
> https://github.com/AI-Planning/planutils
>
> Old installation and user instructions in SMTPlan directory:
> https://github.com/KCL-Planning/SMTPlan/tree/master/SMTPlan
>
> ## Contents
>
> - SMTPlan: source code for SMTPlan+
> - benchmarks: PDDL2.1 and PDDL+ benchmark domains and problems