FROM gcc:latest

COPY build/TP-Refacto /app/

WORKDIR /app

CMD ["/app/TP-Refacto"]

