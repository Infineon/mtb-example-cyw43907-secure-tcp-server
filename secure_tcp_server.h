/******************************************************************************
* File Name:   secure_tcp_server.h
*
* Description: This file contains declaration of task and functions related to
* secure TCP server operation.
*
*******************************************************************************
* $ Copyright 2021 Cypress Semiconductor $
*******************************************************************************/

#ifndef SECURE_TCP_SERVER_H_
#define SECURE_TCP_SERVER_H_

/* Set this macro to '1' to enable IPv6 protocol. Default value is '0' to use
 * IPv4 protocol.
 */
#define USE_IPV6_ADDRESS                          (0)

/* TCP server related macros. */
#define TCP_SERVER_PORT                           (50007)
#define TCP_SERVER_MAX_PENDING_CONNECTIONS        (3)
#define TCP_SERVER_RECV_TIMEOUT_MS                (2000)
#define MAX_TCP_RECV_BUFFER_SIZE                  (20)

/*******************************************************************************
* Function Prototype
********************************************************************************/
void tcp_secure_server_task(void *arg);

#endif /* SECURE_TCP_SERVER_H_ */
