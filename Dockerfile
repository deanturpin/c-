FROM gcc
RUN apt update
RUN apt install -y time
COPY . /src
WORKDIR /src
CMD make CXX=g++
