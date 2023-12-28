FROM gcc:latest

RUN apk add --no-cache cmake build-base

COPY build/TP-Refacto /app/

WORKDIR /app

ENTRYPOINT ["/app/TP-Refacto"]

