/* 8 Bit mesage where 0th bit is reserved->0
 * 1st bit is acknowledgment which is 1 if message is recieved
 * 2nd to 6th bit is for data
 * 7th and 8th bit for identifier
 */

#include <iostream>

using namespace std;
uint8_t func1(uint8_t input);
uint8_t func2(uint8_t input);

int main()
{
    uint8_t a=0xBC; // 8 bit data
    uint8_t b=0x7C; // 8 bit data
    uint8_t z; // ack or if unrecieved by peripheral
   z= func1(a); //calling peripheral 1
   if(z==1)
   {
       cout<<"not in func1 "<<endl;
   }
   else
   {
       cout<<"ack "<<unsigned(z)<<endl;
   }
   z= func2(b); // calling peripheral 2
   if(z==2)
   {
       cout<<"not in func2 "<<endl;
   }
   else
   {
       cout<<"ack "<<unsigned(z)<<endl;
   }




    return 0;
}


uint8_t func1(uint8_t input) //peripheral 1 - id is 10.. 8th bit 1 and 7th bit 0
{
    uint8_t id_mask=0xC0; // masking variable for id
    uint8_t data_mask=0x3C; //masking variable for data
    uint8_t data_value; //value of data
    uint8_t ack=0x82; // acknowledgment first 7th and 6th bit represents id and 2nd bit represents ack
    int result; // converting data into decimal

    // As the data is from 2nd bit to 6th bit.. i.e 4 bits max decimal value can be stored is 15

    if((input & id_mask)==0x80) //masking to check id
    {
        data_value= input&data_mask; //extraction of data by masking
        result=unsigned(data_value)/4;

        cout<<"in func1 data is "<<unsigned(data_value)<<endl;
        cout<<"value in decimal is "<<result<<endl;
        return ack; //returning ack

    }
    return 1;

}


uint8_t func2(uint8_t input) //peripheral 2 - id is 01
{
    uint8_t id_mask=0xC0;
    uint8_t data_mask=0x3C;
    uint8_t data_value;
    uint8_t ack=0x42;
    int result;
    if((input&id_mask)==0x40)
    {
        data_value= data_mask&input;
        result=unsigned(data_value)/4;
        cout<<"in func2 data is "<<unsigned(data_value)<<endl;
        cout<<"value in decimal is "<<result<<endl;
        return ack;
    }
    return 2;

}
