FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    build-essential \
    libcriterion-dev

WORKDIR /app

COPY . /app

RUN make tests

CMD ["./tests"]