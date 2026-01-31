# Use the official Microsoft Dev Container base image
FROM mcr.microsoft.com/devcontainers/base:ubuntu

# Install C++, Java, C#, and MySQL Client/Connector
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    build-essential \
    cmake \
    gdb \
    curl \
    git \
    mysql-client \
    libmysqlcppconn-dev \
    default-libmysqlclient-dev \
    && apt-get clean -y && rm -rf /var/lib/apt/lists/*