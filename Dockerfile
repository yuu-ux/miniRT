FROM ubuntu:22.04

RUN apt-get update && apt-get install -y build-essential xorg libxext-dev zlib1g-dev libbsd-dev git vim

CMD /bin/bash
