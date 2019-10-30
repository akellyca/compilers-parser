# Build a Docker project atop the CIS 461/561 shared platform,
# which is an Ubuntu machine with gcc, build tools including Make,
# and the RE/flex lexical analyzer builder.
#
# To build:
#    docker build --tag=parser .
#
# To run in the resulting Docker container:
#   docker run -it parser
#
FROM michalyoung/cis461:base
COPY . /usr/src/parser
WORKDIR /usr/src/parser
RUN make
