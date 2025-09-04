FROM ubuntu:25.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    libgl1-mesa-dev \
    libx11-dev \
    qt6-base-dev \
    qt6-base-dev-tools \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src
ENV QT_QPA_PLATFORM=xcb
CMD ["/bin/bash"]