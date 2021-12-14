using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mysor
{
    class PurchaseMenu
    {
		public void getText()
		{
			Console.WriteLine("Нажми 1 чтобы добавить покупку");
			Console.WriteLine("Нажми 2 чтобы увидеть все покупки");
			Console.WriteLine("Нажми 3 чтобы перейти назад");
		}
		public void customSwitch()
		{

			switch (Console.ReadLine())
			{
				case "1":
					Menu.menuName = "purchaseAdd";
					break;
				case "2":
					Menu.menuName = "purchaseGet";
					break;
				case "3":
					Menu.menuName = "index";
					break;
			}

		}
	}
}
