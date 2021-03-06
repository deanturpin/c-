FROM gcc
RUN apt update
RUN apt install -y vim
COPY . /src
WORKDIR /src
CMD g++ --version && make CXX=g++
