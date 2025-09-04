# Компиляция
```bash
g++ sample.cc glad/gl.c -Iglad -lglfw -lGL
```

# Запуск
```bash
./a.out
```

# Docker
Сборка контейнера:
```bash
docker compose up --build -d
```

Запуск контейнера:
```bash
docker run -it --rm \
  -e DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -v /dev/dri:/dev/dri \
  -v $PWD:/app \
  opngl-dev \
  bash
```