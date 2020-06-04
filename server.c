# include  < stdio.h >
# include  < string.h > 	// strlen
# include  < sys / socket.h >
# include  < arpa / inet.h > 	// inet_addr
# include  < unistd.h > 	// gravação

int  main ( int argc, char * argv [])
{
	int socket_desc, new_socket, c;
	servidor sockaddr_in struct , cliente;
    char * mensagem;
	
	// Criar socket
	socket_desc = socket (AF_INET, SOCK_STREAM, 0 );
	if (socket_desc == - 1 )
	{
		printf ( " Não foi possível criar o soquete " );
	}
	
	// Prepara a estrutura sockaddr_in
	servidor. família sin_ = AF_INET;
	servidor. sin_addr . s_addr = INADDR_ANY;
	servidor. sin_port = htons ( 8888 );
	
	// Vincular
	if ( bind (socket_desc, ( struct sockaddr *) & server, sizeof (server)) < 0 )
	{
		puts ( " falha na ligação " );
	}
	puts ( " ligação concluída " );
	
	// Listen
	ouvir (socket_desc, 3 );
	
	// Aceita e conexão de entrada
	puts ( " Aguardando conexões de entrada ... " );
	c = sizeof ( struct sockaddr_in);
	while ((new_socket = accept (socket_desc, ( struct sockaddr *) e cliente, ( socklen_t *) & c))))
	{
		puts ( " Conexão aceita " );
		
		// Responder ao cliente
		message = " Olá Cliente, recebi sua conexão. Mas tenho que ir agora, tchau \ n " ;
		write (new_socket, message, strlen (message));
	}
	
	if (new_socket < 0 )
	{
		perror ( " aceitação falhou " );
		retornar  1 ;
	}

	retornar  0 ;
}