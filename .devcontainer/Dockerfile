# Start from the Microsoft Java image
FROM mcr.microsoft.com/devcontainers/java:1-21-bullseye

# FIX: Remove the expired Yarn repository key that causes apt-get update to fail
RUN rm -f /etc/apt/sources.list.d/yarn.list