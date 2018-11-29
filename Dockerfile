FROM gcc
RUN apt update
RUN apt install -y vim
RUN git config --global user.email "you@example.com"
RUN git config --global user.name "Your Name"
COPY . /src
WORKDIR /src
