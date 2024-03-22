#include <stdio.h>
#include "include/indy_mod.h"
#include "include/indy_types.h"
#include "include/indy_wallet.h"

volatile int callback_triggered = 0;

void create_wallet_callback(indy_handle_t command_handle, indy_error_t err)
{
    if (err != 0)
    {
        printf("Error creating wallet: %d\n", err);
    }
    else
    {
        printf("Wallet created successfully\n");
    }

    callback_triggered = 1;
}

int main()
{
    const char *config = "{\"id\": \"testfromc\"}";
    const char *credentials = "{\"key\": \"my_key\"}";

    int err = indy_create_wallet(0, config, credentials, create_wallet_callback);
    printf("Error creating wallet: %d\n", err);

    // Wait for the callback to be triggered
    while (!callback_triggered)
    {
        // You might want to add a delay here to avoid busy waiting
    }

    return 0;
}