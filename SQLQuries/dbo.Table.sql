CREATE TABLE [dbo].[Tasks] (
    [Id]         INT           NOT NULL,
    [Title]      VARCHAR (50)  NOT NULL,
    [Desc]       VARCHAR (250) NULL,
    [DeadLine]   DATETIME      NOT NULL,
    [Status]     INT           NOT NULL,
    [CategoryID] INT           NULL,
    PRIMARY KEY CLUSTERED ([Id] ASC)
);

