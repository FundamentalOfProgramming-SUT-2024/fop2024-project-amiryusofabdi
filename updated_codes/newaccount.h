char str_id[4] = "000-";

char* Int2String(int num){
    
    
    int index = 2;

    while (num > 0){
        str_id[index] = (char) ('0'+ num%10);
        index --;
        num /= 10;
    }

    return str_id;

}

void newaccount(char username[], char email[], char password[]) {


    // Generating ID
    int num = rand()%1000;

    char* id = Int2String(num);



    FILE *fptr_file_username;
    fptr_file_username = fopen("usernames.txt","a");
    fprintf(fptr_file_username,id);
    fprintf(fptr_file_username,username);
    fprintf(fptr_file_username,"\n");

    FILE *fptr_file_password;
    fptr_file_password = fopen("passwords.txt","a");
    fprintf(fptr_file_password,id);
    fprintf(fptr_file_password,password);
    fprintf(fptr_file_password,"\n");

    FILE *fptr_file_email;
    fptr_file_email = fopen("emails.txt","a");
    fprintf(fptr_file_email,id);
    fprintf(fptr_file_email,email);
    fprintf(fptr_file_email,"\n");


    fclose(fptr_file_username);
    fclose(fptr_file_password);
    fclose(fptr_file_email);

}