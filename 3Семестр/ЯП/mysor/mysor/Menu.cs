using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mysor
{
	class Menu
	{
		static public string menuName = "index";
		public void start()
		{
			while (true)
			{
				if (menuName == "index")
				{
					Console.Clear();
					MenuIndex menuIndex = new MenuIndex();
					menuIndex.getText();
					menuIndex.customSwitch();

				}
				else if(menuName == "tovar")
                {
					Console.Clear();
					TovarMenu tovarIndex = new TovarMenu();
					tovarIndex.getText();
					tovarIndex.customSwitch();
				}
				else if (menuName == "tovarAdd")
				{
					Console.Clear();
					MenuTovarAdd tovarAdd = new MenuTovarAdd();
					tovarAdd.start();
				}
				else if (menuName == "tovarGet")
				{
					Console.Clear();
					MenuTovarGet tovarGet = new MenuTovarGet();
					tovarGet.getText();
				}

				else if (menuName == "client")
				{
					Console.Clear();
					MenuClient menuClient = new MenuClient();
					menuClient.getText();
					menuClient.customSwitch();

				}
				else if(menuName == "clientAdd") {
					Console.Clear();
					MenuClientAdd menuClientAdd = new MenuClientAdd();
					menuClientAdd.start();
				}
				else if(menuName == "clientGet") {
					Console.Clear();
					MenuCLientGet menuCLientGet = new MenuCLientGet();
					menuCLientGet.getText();
				}
			}
		 
		}
	}
}
