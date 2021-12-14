using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mysor
{
	class MenuIndex{
		public void getText() {
			Console.WriteLine("Нажми 1 чтобы посмотреть клиентов");
			Console.WriteLine("Нажми 2 чтобы посмотреть товары");
			Console.WriteLine("Нажми 3 чтобы посмотреть покупки");

		}
		public void customSwitch() {
				switch (Console.ReadLine())
				{
					case "1":
						Menu.menuName = "client";
						break;
					case "2":
						Menu.menuName = "tovar";
						break;
					case "3":
						Menu.menuName = "purchase";
						break;
				}
		}
	}
}
