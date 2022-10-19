# SMTPlan+
This is a fork repository of [SMTPlan+](https://github.com/KCL-Planning/SMTPlan).

The SMTPlan+ cannot be compiled on Ubuntu 20.04 or later, so this repository gives you easy ways to build it on any environments. Some other changes were also made.

What has changed from the original:

- Add Singularity definition files so that you can easily build an image to execute SMTPlan+.
    - You can build the image and install SMTPlan+ by running [install.sh](install.sh).
    - Using Singularity, you can run SMTPlan+ on your host emvironment after installation.
- Add Dockerfiles, too.
    - You can build the Docker image by running [docker_build.sh](docker_build.sh).
    - Using Docker, you can run SMTPlan+ on any containers over the smtplan:latest image.
- Remove unused files and libraries.
- Remove EncoderFluent since it doesn't work well.
- The format of printing plans solved.

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