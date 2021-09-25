using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mysor
{
    class TovarMenu
    {
		public void getText()
		{
			Console.WriteLine("Нажми 1 чтобы добавить товар");
			Console.WriteLine("Нажми 2 чтобы увидеть всех товары");
			Console.WriteLine("Нажми 3 чтобы перейти назад");
		}

		public void customSwitch()
		{

			switch (Console.ReadLine())
			{
				case "1":
					Menu.menuName = "tovarAdd";
					break;
				case "2":
					Menu.menuName = "tovarGet";
					break;
				case "3":
					Menu.menuName = "index";
					break;
			}

		}
	}
}
