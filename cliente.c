# include  < stdio.h >
# include  < string.h > 	// strlen
# include  < unistd.h >  // fechar
# include  < sys / socket.h > 
# include  < arpa / inet.h > 	// inet_addr

int  main ( int argc, char * argv [])
{
	int socket_desc;
    servidor struct sockaddr_in;
    char * mensagem, server_reply [ 2000 ];

    // Criar socket
	socket_desc = socket (AF_INET, SOCK_STREAM, 0 );
	
	if (socket_desc == - 1 )
	{
		printf ( " Impossível criar socket " );
	}
	
    servidor. sin_addr . s_addr = inet_addr ( " 127.0.0.1 " );
	servidor. família sin_ = AF_INET;
	servidor. sin_port = htons ( 8888 );

	// Conectar ao soquete remoto
	if ( connect (socket_desc, ( struct sockaddr *) & server, sizeof (server)) < 0 )
	{
		puts ( " erro de conexão " );
		retornar  1 ;
	}
	
	puts ( " Conectado " );
	
    // Envia dados
	message = " Olá, mundo! \ n " ;
	if ( send (socket_desc, message, strlen (message), 0 ) < 0 )
	{
		puts ( " Falha ao enviar " );
		retornar  1 ;
	}
	puts ( " Dados enviados \ n " );
	
	// Recebe resposta do servidor
	if ( recv (socket_desc, server_reply, 2000 , 0 ) < 0 )
	{
		puts ( " Falha ao receber. " );
        retornar  1 ;
	}
	puts ( " Resposta recebida \ n " );
	puts (resposta do servidor);

    fechar (socket_desc); // termina o soquete

	retornar  0 ;
}