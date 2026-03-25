#!/bin/bash
set -e

echo "🔧 Instalando dependencias del sistema..."
sudo apt-get update -y
sudo apt-get install -y \
    libsfml-dev \
    cmake \
    build-essential \
    ninja-build \
    gdb \
    xvfb \
    x11-utils \
    libx11-dev \
    libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libgl1-mesa-dev \
    libfreetype-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev


echo "🏗️  Configurando el proyecto CMake..."
mkdir -p build
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
echo "✅ Entorno listo. Usa 'cmake --build build' para compilar."

#nohup bash -c 'while :; do
#  echo [$(date)] Process started.
#  tigervncserver :1 -geometry 1440x768 -depth 24 -rfbport 5901 -dpi 96 -localhost -desktop fluxbox -fg -SecurityTypes None
#  echo [$(date)] Process exited!
#  sleep 5
#done' >/home/vscode/.vnc-loop.log 2>&1 &
# este va al devcontainer :  tigervncserver -kill :1 ; sleep 1 ; 