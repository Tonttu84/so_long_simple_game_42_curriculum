FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    libxext-dev \
    libx11-dev \
    libbsd-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN make

CMD ["./so_long maps/map.ber"]
