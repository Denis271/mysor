using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;

namespace mysor
{

	public class PurchaseDataArray
	{

		[XmlArray("purchases")]
		[XmlArrayItem("purchase")]
		public List<PurchaseData> data = new List<PurchaseData>();
	}
	[Serializable]
	[XmlRoot("dataPurchase")]
	public class PurchaseData
	{
		[XmlElement("client")]
		public ClientData client = new ClientData();
		[XmlAttribute("date")]
		public DateTime date;

		[XmlArray("tovars")]
		[XmlArrayItem("tovar")]
		public List<TovarData> tovar = new List<TovarData>();

	}

	class Purchase
	{
		string nameFile = "purchase.txt";
		XmlSerializer serializer = new XmlSerializer(typeof(PurchaseDataArray));
		public void setPurchase(PurchaseData dataArray)
		{
			PurchaseDataArray allData = getPurchase();
			allData.data.Add(dataArray);
			using (var fs = new FileStream(nameFile, FileMode.Create))
			{
				serializer.Serialize(fs, allData);
			}
		}
		public PurchaseDataArray getPurchase()
		{
			PurchaseDataArray PurchaseData = new PurchaseDataArray();
			Stream streamout = new FileStream(nameFile, FileMode.Open, FileAccess.Read);
			if (streamout.Length == 0)
			{
				streamout.Close();
				return PurchaseData;
			}
			PurchaseData = (PurchaseDataArray)serializer.Deserialize(streamout);
			streamout.Close();
			return PurchaseData;
		}

		public void getPurchaseAddConsole(PurchaseData purchase)
		{
			Console.WriteLine("ФИО  " + "Возраст  " + "Номер телефона  " + "Дата заказа  "); 
			Console.WriteLine(purchase.client.FIO + " " + purchase.client.age + " " + purchase.client.tlf + " " + purchase.date);
			Console.WriteLine("Наименование товара  " + "Цена товара  ");
			int index = 0;
			foreach (TovarData data in purchase.tovar)
            {
				index++;
				Console.WriteLine( data.name + "    " + data.price);
			}
		}

		public PurchaseDataArray getPurchaseClientConsole()
		{
			int index = 0;
			PurchaseDataArray purchaseData = getPurchase();
			Console.WriteLine("Номер " + "ФИО  " + "Возраст  " + "Номер телефона  " + "Дата заказа  ");
			foreach (PurchaseData data in purchaseData.data)
			{
				index++;
				Console.WriteLine(data.client.FIO + " " + data.client.age + " " + data.client.tlf + " " + data.date);
				 
			}
			return purchaseData;
		}

		public void deleteTovar(int indexDelete)
		{
			int index = 0;
			PurchaseDataArray data = getPurchase();
			PurchaseDataArray dataSetArray = new PurchaseDataArray();

			foreach (PurchaseData dataIndex in data.data)
			{
				if (index != indexDelete)
				{
					dataSetArray.data.Add(dataIndex);
				}
				index++;
			}
			using (var fs = new FileStream(nameFile, FileMode.Create))
			{
				serializer.Serialize(fs, dataSetArray);
			}
		}
	}
}
