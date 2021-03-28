#ifndef PIPE_H
#define PIPE_H


class Pipe
{
public:
    Pipe();
    Pipe(int[2]);
    ~Pipe();
    void setPipes(int[2]);
    int getPipesEnvio();
    int getPipeRecibir();

private:
    int pipes[2];
};

#endif // PIPE_H
