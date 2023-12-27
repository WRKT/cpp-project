FROM alpine:latest

WORKDIR /app

COPY build/TP-Refacto /app/

ENTRYPOINT ["/app/TP-Refacto"]

