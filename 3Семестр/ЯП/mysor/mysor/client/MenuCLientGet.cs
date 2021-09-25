using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mysor
{
    class MenuCLientGet
    {
		public void getText()
		{
			Console.WriteLine("Нажми 0 чтобы перейти назад");
			Console.WriteLine("Нажмите на номер записи что бы перейди к ней");
			Client clientServer = new Client();
			ClientDataArray data = clientServer.getConsole();
			string str = Console.ReadLine();
			switch (str)
			{
				case "0":
					Menu.menuName = "client";
					break;
				default:
					Console.Clear();
					Console.WriteLine("Нажми 0 чтобы перейти назад");
					Console.WriteLine("Нажми 1 чтобы удалить выбранную запись");
					string str1 = Console.ReadLine();
					switch (str1)
					{
						case "0":
							break;
						case "1":				
							Client client = new Client();
							client.deleteClient(Convert.ToInt32(str1) - 1);
							break;
					}
					break;
			}

		}
	}
}
