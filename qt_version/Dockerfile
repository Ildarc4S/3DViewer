FROM ubuntu:25.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y wget gnupg2 software-properties-common

RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | gpg --dearmor -o /usr/share/keyrings/llvm.gpg && \
  echo "deb [signed-by=/usr/share/keyrings/llvm.gpg] http://apt.llvm.org/mantic/ llvm-toolchain-mantic-18 main" > /etc/apt/sources.list.d/llvm.list && \
  apt-get update && \
  apt-get install -y \
    build-essential \
    libgtest-dev \
    cmake \
    python3-pip \
    git \
    lcov \
    valgrind \
    cppcheck \
    clang-format-18 \
    libgl1-mesa-dev \
    libx11-dev \
    qt6-base-dev \
    qt6-base-dev-tools && \
  apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /project

COPY . .

ENV QT_QPA_PLATFORM=xcb
CMD ["/bin/bash"]
