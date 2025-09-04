# Компиляция
```bash
g++ sample.cc glad/gl.c -Iglad -lglfw -lGL
```

# Запуск
```bash
./a.out
```

# Docker
1. Сборка и запуск
```bash
docker compose up --build -d
```

2. Вход в контейнер
```bash
docker compose exec opengl-app bash
```

3. Внутри контейнера работаем с проектом
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
./HelloWorld
```

4. Выходим и останавливаем
```bash
exit
docker compose down
```