FROM gcc:latest

WORKDIR /usr/src/bloomfilter

COPY ./src/ .

RUN g++ -o bloomfilter *.cpp

EXPOSE 5555

CMD ["./bloomfilter"]
