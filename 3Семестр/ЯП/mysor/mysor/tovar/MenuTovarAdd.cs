using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mysor
{
    class MenuTovarAdd
    {
        public void start()
        {
            TovarData dataArray = new TovarData();
            Console.WriteLine("Введите имя товара");
            dataArray.name = Console.ReadLine();
            Console.WriteLine("Введите цену товара");
            dataArray.price = Console.ReadLine();
            Tovar tovarServer = new Tovar();
            tovarServer.setTovar(dataArray);
            Menu.menuName = "tovar";

        }
    }
}
