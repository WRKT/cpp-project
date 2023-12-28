FROM gcc:latest

COPY build/TP-Refacto /app/

WORKDIR /app

ENTRYPOINT ["/app/TP-Refacto"]

