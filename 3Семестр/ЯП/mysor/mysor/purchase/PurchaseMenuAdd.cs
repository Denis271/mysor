using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mysor
{
    class PurchaseMenuAdd
    {
        Purchase purchase = new Purchase();
        PurchaseData purchase_data = new PurchaseData();
        Client client = new Client();
        Tovar tovar = new Tovar();
        int status = 0;
        public void customSwitch()
        {
            while (true)
            {
                if (status == 0)
                {
                    Console.WriteLine("Укажите номер клиента который интересует");
                    client.getConsole();
                    string user_index = Console.ReadLine();
                    int index = Convert.ToInt32(user_index);
                   purchase_data.client = client.clientIndex(index);
                    status = 1;
                }
                if(status == 1)
                {
                    Console.WriteLine("Укажите товар");
                    tovar.getTovarConsole();
                    string tovar_index = Console.ReadLine();
                    int index = Convert.ToInt32(tovar_index);
                    purchase_data.tovar.Add(tovar.tovarIndex(index-1));
                    status = 2;
                }
                if(status == 2)
                {
                    purchase.getPurchaseAddConsole(purchase_data);
                    Console.WriteLine("Нажми на 1 если нужно добавить еще товар");
                    Console.WriteLine("Нажми на 2 если заказ готов");
                    string statusNews = Console.ReadLine();
                    if(statusNews == "1")
                    {
                        status = 2;
                    }
                    if (statusNews == "2")
                    {
                        status = 3;
                    }

                }
                if(status == 3)
                {
                    purchase.setPurchase(purchase_data);
                    status = 0;
                }
            }
      
  
        }
    }
}
