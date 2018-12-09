# Clean up Docker
# docker rm -v $(docker ps -qa)

FROM gcc
RUN apt update
RUN apt install -y vim
COPY . /src
WORKDIR /src
