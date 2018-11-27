FROM kalilinux/kali-linux-docker
RUN apt update
RUN apt install -y clang++-7
RUN apt install -y clang-format
RUN apt install -y g++-8
RUN apt install -y make
RUN apt install -y git
RUN apt install -y vim
RUN git config --global user.email "you@example.com"
RUN git config --global user.name "Your Name"
COPY . /src
WORKDIR /src
CMD make
