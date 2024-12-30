
void newaccount(char username[], char email[], char password[]){

    FILE *fptr_file_username;
    fptr_file_username = fopen("usernames.txt","a");
    fprintf(fptr_file_username,username);

    FILE *fptr_file_password;
    fptr_file_password = fopen("passwords.txt","a");
    fprintf(fptr_file_password,password);

    FILE *fptr_file_email;
    fptr_file_email = fopen("email.txt","a");
    fprintf(fptr_file_email,email);


    fclose(fptr_file_username);
    fclose(fptr_file_password);
    fclose(fptr_file_email);

}