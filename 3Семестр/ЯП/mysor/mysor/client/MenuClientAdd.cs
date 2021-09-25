using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mysor
{
    class MenuClientAdd
    {
       public void start()
        {
            ClientData dataArray = new ClientData();
            Console.WriteLine("Введите ФИО клиента");
            dataArray.FIO = Console.ReadLine();
            Console.WriteLine("Введите возраст клиента");
            dataArray.age = Console.ReadLine();
            Console.WriteLine("Введите номер телефона клиента");
            dataArray.tlf = Console.ReadLine();
            Client clientServer = new Client();
            clientServer.setClient(dataArray);
            Menu.menuName = "client";
        }
    }
}
