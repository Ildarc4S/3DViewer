APP_NAME ?= HelloWorld

DOCKER_COMPOSE = docker compose
DOCKER_EXEC = $(DOCKER_COMPOSE) exec opengl-app

.PHONY: all build up build-app run clean help down logs shell

all: build up build-app
docker-build: build up

build:
	$(DOCKER_COMPOSE) build

up:
	$(DOCKER_COMPOSE) up -d

down:
	$(DOCKER_COMPOSE) down

build-app:
	$(DOCKER_EXEC) bash -c "mkdir -p build && cd build && cmake .. && cmake --build . -- -j4"

run:
	$(DOCKER_EXEC) ./build/$(APP_NAME)

clean:
	$(DOCKER_EXEC) bash -c "rm -rf build"

rebuild: clean build-app

shell:
	$(DOCKER_EXEC) bash

help:
	@echo "Доступные цели:"
	@echo "  make all              - Собрать всё (build + up + build-app)"
	@echo "  make docker-build     - Собрать Docker образ и запустить"
	@echo "  make build            - Собрать Docker образ"
	@echo "  make up               - Запустить контейнеры"
	@echo "  make down             - Остановить контейнеры"
	@echo "  make build-app        - Собрать приложение"
	@echo "  make run APP_NAME=xxx - Запустить приложение (по умолчанию: HelloWorld)"
	@echo "  make clean            - Очистить билд директорию"
	@echo "  make rebuild          - Пересобрать приложение"
	@echo "  make shell            - Войти в контейнер"
	@echo "  make help             - Показать справку"