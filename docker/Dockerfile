# A image to build SMTPlan+
FROM smtplan:build_environment AS builder

# Copy source files
COPY src /home/src

# Build SMTPlan+
RUN cd /home/src && \
    mkdir build && cd build && \
    cmake .. && \
    make -j4


# A image to run SMTPlan+
FROM ubuntu:16.04 AS runner

ENV DEBCONF_NOWARNINGS=yes

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install --no-install-recommends -y \
        libgmp3-dev \
        libmpfr-dev && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /home/src/build/SMTPlan /bin/SMTPlan

ENTRYPOINT /bin/SMTPlan $@