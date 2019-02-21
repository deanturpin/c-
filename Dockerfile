FROM gcc
RUN apt update
RUN apt install -y time vim
COPY . /src
WORKDIR /src
CMD make CXX=g++
