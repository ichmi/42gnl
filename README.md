# 42gnl
O projeto se baseia em programar uma funcao da qual retorne uma linha de um determinado _File Descriptor_. O projeto nos apresenta o conceito de Buffer, e tambem como podemos aplicar a tecnica atraves de variaveis estaticas (`static`).

A fim de testar a funcao, basta especificar algum file descriptor no arquivo `main.c`, por exemplo:
```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	// Especificar o nome do arquivo ("file1" Por exemplo)
	int	fd = open("file1", O_RDONLY);
	char *p = get_next_line(fd);
	while (p)
	{
		printf("%s", p);
		free(p);
		p = get_next_line(fd);
	}
	free(p);
	close(fd);
	return (0);
}
```
Perceba o padrao, cada chamada de `get_next_line` retorna uma linha de um determinado file descriptor. A ideia eh usar um buffer atraves de uma variavel estatica **`static char *acc`**, e conforme a gente insere itens no buffer, atualizamos o valor da variavel a fim de sempre manter o tracking da proxima linha.

Para testar, basta compilarmos os `.c`:
```sh
gcc main.c get_next_line.c get_next_line_utils.c # Default BUFFER_SIZE=5
# ou
gcc *.c
```

Caso queira determinar o tamanho do Buffer, basta inserir a flag `-D` da qual ira pre-definir um macro para ser usado durante o pre-processing:
```sh
gcc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=10000000
# ou
gcc *.c -D BUFFER_SIZE=1
```

Feito isso, basta executar o processo:
```sh
./a.out
```

Caso queira testar com `fd = 0` (_stdin_):
```sh
echo "foo\nbar\nbaz!" | ./a.out
# foo
# bar
# baz!
```
