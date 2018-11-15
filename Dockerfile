FROM deanturpin/cpp
RUN git clone https://github.com/deanturpin/cpp
CMD /usr/bin/make -C cpp
